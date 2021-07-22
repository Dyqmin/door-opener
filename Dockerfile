FROM node:16-alpine

WORKDIR /usr/src/app
COPY package*.json ./
COPY . .

# Adding necessary dependencies to make serialport package install on alpine image
# Docs: https://serialport.io/docs/guide-installation/#alpine-linux
RUN apk add --no-cache make gcc g++ python3 linux-headers udev
RUN npm install serialport --build-from-source=serialport

RUN npm install --only=production
EXPOSE 3000
CMD npm start
