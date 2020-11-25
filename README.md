# Greeeeeeeeeeeeeeeeet! 



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
$ git clone https://github.com/suam-team/stack-buf-overflow-101-lab.git
$ cd stack-buf-overflow-101-lab
$ docker build -t stack-buf-overflow-101-lab .
$ docker run -d --rm -p 1337:1337 -e PORT=1337 -e FLAG=flag{ILoveU} stack-buf-overflow-101-lab
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
