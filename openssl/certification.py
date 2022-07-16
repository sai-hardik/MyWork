import ssl
import urllib
url = 'https://www.google.com'
addr = urllib.parse.urlsplit(url).hostname
port = 443
cert = ssl.get_server_certificate((addr, port), ssl_version=2)
print(cert)
