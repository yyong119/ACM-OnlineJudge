import urllib2
response = urllib2.urlopen('http://www.baidu.com')
content = response.read()
print(content)
