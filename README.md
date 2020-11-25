# PWN Greeeeeeeeeeeeeeeeet

เป็นโจทย์ง่าย ๆ ไว้หัดทำการโจมตีแบบ Stack-based Buffer Overflow โดยโจทย์นี้ทำการปิด Protection ทั้งหมดเพื่อให้ง่ายต่อการโจมตี

ปล. โจทย์นี้ใช้ในการบรรบาย OWASP รายเดือนครั้งสุดท้ายของปี 2020 ในหัวข้อ From 0x00 to 0x41: An Introduction to Memory Corruption

## Let Play

Please find a bud in the [greet.c](/greet.c) file. Then, hack this lab on your own environment. Next, get a real flag `ws://pwn-greeeeeeeeeeeeeeeeet.herokuapp.com`. Finally, submit flag on [https://lab.suam.wtf/](https://lab.suam.wtf/).

## WebSocket PWN

In heroku platform, we can deploy only web application. Thus, we deployed the PWN challenge using WebSocket protocol. Enjoy WebSocket below !

### netcat to wscat

Connect to lab app with wscat instead. To install wscat, NPM is required.

```
$ npm install -g wscat
$ wscat -c ws://echo.websocket.org
Connected (press CTRL+C to quit)
> hi there
< hi there
> are you a happy parrot?
< are you a happy parrot?
```

### pwnlib.tubes.remote.remote to sock_websocket.WebSock

Connect to lab app with sock_websocket.WebSock instead.

```
$ pip install sock-websocket
[...]
$ cat echo.py
from pwn import *
from sock_websocket import WebSock

# s = process("chall")
# s = remote("1.3.3.7", 1337)
s = WebSock("ws://echo.websocket.org")
s.sendline(b"Hello World !"))
s.interactive()

$ python echo.py                                 
Hello World !
<3
<3
```

## Running Locally

Make sure you have Python 3.7 [installed locally](http://install.python-guide.org). To push to Heroku, you'll need to install the [Heroku CLI](https://devcenter.heroku.com/articles/heroku-cli).

```sh
$ git clone https://github.com/suam-team/pwn-Greeeeeeeeeeeeeeeeet.git
$ cd pwn-Greeeeeeeeeeeeeeeeet
$ docker build -t pwn-Greeeeeeeeeeeeeeeeet .
$ docker run -d --rm -p 1337:1337 -e PORT=1337 -e FLAG=flag{ILoveU} pwn-Greeeeeeeeeeeeeeeeet
```

Your app should now be running on `ws://localhost:1337`.

## Deploying to Heroku

```sh
$ heroku create
$ heroku config:set FLAG=flag{ILoveU}
$ git push heroku main
$ heroku open
```
or

[![Deploy](https://www.herokucdn.com/deploy/button.svg)](https://heroku.com/deploy)
