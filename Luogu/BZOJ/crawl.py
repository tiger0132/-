import urllib.request


def getHtml(url):
    html = urllib.request.urlopen(url).read()
    return html


def saveHtml(file_name, file_content):
    with open(file_name.replace('/', '_') + ".html", "wb") as f:
        f.write(file_content)


aurl = "http://www.view.sdu.edu.cn/info/1003/75240.htm"
html = getHtml(aurl)
saveHtml("sduview", html)

print("下载成功")
