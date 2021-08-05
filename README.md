# Project info
Door opener is a simple project to simulate button clicking on doors remote.

## ...but why?
We have no reception at our office, so we had to open doors using remote
by ourselves by every time doorbell rings.

## How does it work?
Express server is a message handler for our ESP8266 (or any MCU). 
It receives a command to open digital pin, which is signal for a relay 
to simulate a click. 
Here is the video of working [demo](https://twitter.com/DvDomin/status/1419543709373304833).

## Install using Docker
Build the image
```
$ docker build . -t door-opener/app
```

Run the image
```
$ docker run -p 3000:3000 -d door-opener/app --privileged -v {{HOST_PORT_NAME}}:/dev/tty node bash
```

