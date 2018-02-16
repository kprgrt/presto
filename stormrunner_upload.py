import zipfile
import os
import json
import imp
import argparse
from setuptools.command import easy_install


def zipDir(source_dir,output_filename):
    relroot = os.path.abspath(os.path.join(source_dir, os.pardir))
    with zipfile.ZipFile(output_filename, "w", zipfile.ZIP_DEFLATED) as zip:
        for root, dirs, files in os.walk(source_dir):
            # add directory (needed for empty dirs)
            zip.write(root, os.path.relpath(root, relroot))
            for file in files:
                    filename = os.path.join(root, file)
                    if os.path.isfile(filename): # regular files only
                        arcname = os.path.join(os.path.relpath(root, relroot), file)
                        zip.write(filename, arcname)
                        
def getTokenAndScripts(signin_url,user_name,password,tenant):
    global cookie
    global proxy
    payload = { "user": user_name, "password": password }
    headers = {
        'accept': 'application/json',
        'content-type': 'application/json'
    }
    proxy = { 
        "http"  : "http://ep.threatpulse.net:80"
    }
    # Send the request to the server
    req = requests.post(signin_url, json=payload, headers=headers, proxies=proxy)
    req.raise_for_status()                   
    # Get the response
    response = json.loads(req.content.decode('utf-8'))
    token = response["token"]
    #print('\tToken: {token}'.format(token=token))
    getScripts_url = "https://stormrunner-load.saas.hpe.com/v1/projects/1/scripts?TENANTID="+tenant
    cookie = {'LWSSO_COOKIE_KEY': token}
    r = requests.get(getScripts_url,cookies=cookie,proxies=proxy)
    json_str = json.dumps(r.json())
    json_file = open(source_dir+"/"+"scripts.json",'w')
    json_file.write(json_str)
    json_file.close()
    #f = open(source_dir+"\\"+"scripts.json",'w') 
    #f.write(str(r.content))
    #f.close()

parser = argparse.ArgumentParser()
parser.add_argument("sourceDir", help="test scripts location",type=str)
parser.add_argument("userName", help="login username of stormrunner",type=str)
parser.add_argument("password", help="login password of stormrunner",type=str)
parser.add_argument("tenant", help="stormrunner tenant id",type=str)
parser.add_argument("targetIP", help="dynamic IP of target resource",type=str)
args = parser.parse_args()

source_dir = args.sourceDir+"/"
user_name = args.userName
password = args.password
tenant = args.tenant
target_ip = args.targetIP
signin_url = "https://stormrunner-load.saas.hpe.com/v1/auth?TENANTID="+tenant
token = ""
proxy = ""
cookie = {'LWSSO_COOKIE_KEY': token}
i=0
	
try:
    imp.find_module('requests')
    print("requests package is already installed")
except ImportError:
    print("requests package not found, installing...")
    easy_install.main(["-U","requests"])
    
import requests

folders = next(os.walk(source_dir))[1]
for folder in folders:
    if (folder != ".git"):
      file = source_dir+folder+"/URL.dat"
      print("Updating "+target_ip+" in " +folder)
      wr = open(file, 'w')
      wr.write("URL\n")
      wr.write(target_ip)
      wr.close()
      output_filename = source_dir+folder+".zip"
      print("zipping "+output_filename)
      zipDir(source_dir+"/"+folder, output_filename)

getTokenAndScripts(signin_url,user_name,password,tenant)

jsonFile = open(source_dir+'/scripts.json', 'r')
values = json.load(jsonFile)
jsonFile.close()
 
folders = next(os.walk(source_dir))[1]
     
#print(len(values))
while(i < len(values)):
    for script_name in folders:
        if (values[i]['name'] == script_name):
            #print(values[i]['id'])
            script_id = values[i]['id']
            upload_url = "https://stormrunner-load.saas.hpe.com/v1/projects/1/scripts/"+str(script_id)+"/file?TENANTID="+tenant
            fin = open(source_dir+script_name+'.zip','rb')
            files = {'file': fin}
            try:
                print("Uploading "+script_name+".zip to stormrunner using "+upload_url)
                r1 = requests.put(upload_url,cookies=cookie,files=files,proxies=proxy)
            finally:
                fin.close()
            break
    i=i+1
