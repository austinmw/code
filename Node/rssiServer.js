/*
EC544: Networking the Physical World
Boston University
Fall 2016

Challenge 6: Indoor Position Localization

Group 4 Members:

Dami Orikogbo
Austin Welch
Jo-Ann Meunier
Kiran Vishal

*/
var SerialPort = require("serialport");
var app = require('express')();
var xbee_api = require('xbee-api');
var http = require('http').Server(app);
var io = require('socket.io')(http);
var math = require('mathjs');

var C = xbee_api.constants;
var XBeeAPI = new xbee_api.XBeeAPI({
    api_mode: 2
});

/* ----------- HTML Pages ------------ */

app.get('/', function(req, res) {
    res.sendFile('/Users/damiOr/Documents/Grad_School/ec544/git/challengeSix/rssi/public/index.html');
});


//takes sample every 2 seconds
var sampleDelay = 2000;

/*----------- Beacon Data point arrays --------------- */
var r1 = [];
var r2 = [];
var r3 = [];
var r4 = [];


/*----------- Connecting to Mongo --------------- */

var MongoClient = require('mongodb').MongoClient;
var assert = require('assert');
var ObjectId = require('mongodb').ObjectID;
var url = 'mongodb://localhost:27017/chal6';



//Note that with the XBeeAPI parser, the serialport's "data" event will not fire when messages are received!
portConfig = {
    baudRate: 9600,
    parser: XBeeAPI.rawParser()
};

var sp;
sp = new SerialPort.SerialPort(portName, portConfig);


//Create a packet to be sent to all other XBEE units on the PAN.
// The value of 'data' is meaningless, for now.
var RSSIRequestPacket = {
    type: C.FRAME_TYPE.ZIGBEE_TRANSMIT_REQUEST,
    destination64: "000000000000ffff",
    broadcastRadius: 0x01,
    options: 0x00,
    data: "test"
}

var requestRSSI = function() {
    sp.write(XBeeAPI.buildFrame(RSSIRequestPacket));
}

sp.on("open", function() {
    console.log('open');
    requestRSSI();
    setInterval(requestRSSI, sampleDelay);
});

XBeeAPI.on("frame_object", function(frame) {
    if (frame.type == 144) {

        console.log("Beacon ID: " + frame.data[1] + ", RSSI: " + (frame.data[0]));
        var beconID = frame.data[1];
        var rssiVal = frame.data[0];

        if (beconID == 1) {
            r1.push(rssiVal);
            console.log("Added to BEACON 1: " + beconID);
        }

        if (beconID == 2) {
            r2.push(rssiVal);
            console.log("Added to BEACON 2: " + beconID);
        }

        if (beconID == 3) {
            r3.push(rssiVal);
            console.log("Added to BEACON 3: " + beconID);
        }

        if (beconID == 4) {
            r4.push(rssiVal);
            console.log("Added to BEACON 4: " + beconID);
        }


        MongoClient.connect(url, function(err, db) {
            if (err) {
                console.log('Unable to connect to the mongoDB server. Error:', err);
            } else {

                db.collection('beacon').insert({
                    "Router_Number": beconID,
                    "Time": getFormattedDate(),
                    "RSSI": rssiVal,
                    "Bin_Number": binNum,
                }, function(err, records) {
                    if (err) console.log("dups"); // err;

                });

            }
        }); //end of Mongo DB 
    }

});