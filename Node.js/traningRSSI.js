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

Collecting data points in order to fingerprint the indoor wireless signal strength from XBees placed on a floor
Collects 10 datapoints per location, averages them and stores in MongoDB

*/
var SerialPort = require("serialport");
var app = require('express')();
var xbee_api = require('xbee-api');
var http = require('http').Server(app);
var io = require('socket.io')(http);
var math = require('mathjs');
var excel = require('exceljs');


var C = xbee_api.constants;
var XBeeAPI = new xbee_api.XBeeAPI({
    api_mode: 2
});

// arguments used by program
var portName = process.argv[2];
var binNum = process.argv[3];

//takes sample every 2 seconds
var sampleDelay = 2000;


/*----------- Beacon Data point arrays --------------- */
var r1 = [];
var r2 = [];
var r3 = [];
var r4 = [];
var finalPoints = [];

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
        //console.log(frame);

        console.log("Beacon ID: " + frame.data[1] + ", RSSI: " + (frame.data[0]));
        var beconID = frame.data[1];
        var rssiVal = frame.data[0];


        /*----------- Add RSSI val to corresponding beacon array --------------- */
        if (beconID == 1) {
            r1.push(rssiVal);
            console.log("Added to BEACON 1: " + rssiVal);
            console.log('\r\n');
        }

        if (beconID == 2) {
            r2.push(rssiVal);
            console.log("Added to BEACON 2: " + rssiVal);
            console.log('\r\n');
        }

        if (beconID == 3) {
            r3.push(rssiVal);
            console.log("Added to BEACON 3: " + rssiVal);
            console.log('\r\n');
        }

        if (beconID == 4) {
            r4.push(rssiVal);
            console.log("Added to BEACON 4: " + rssiVal);
            console.log('\r\n');
        }

        if ((r1.length >= 10) && (r2.length >= 10) && (r3.length >= 10) && (r4.length >= 10)) {

            var avg1 = math.mean(r1);
            var avg2 = math.mean(r2);
            var avg3 = math.mean(r3);
            var avg4 = math.mean(r4);
            console.log("Beacon 1 Avg: ", avg1);
            console.log("Beacon 2 Avg: ", avg2);
            console.log("Beacon 3 Avg: ", avg3);
            console.log("Beacon 4 Avg: ", avg4);
            console.log('\r\n');

            MongoClient.connect(url, function(err, db) {
                if (err) {
                    console.log('Unable to connect to the mongoDB server. Error:', err);
                } else {
                    console.log('CONNECTED! ');
                    db.collection('training').insert({
                        "Bin_Number": binNum,
                        "Beacon_1": avg1,
                        "Beacon_2": avg2,
                        "Beacon_3": avg3,
                        "Beacon_4": avg4,
                    }, function(err, records) {
                        if (err) console.log("dups"); // err;
                    });

                }
            }); //end of Mongo DB 
            r1.length = 0;
            r2.length = 0;
            r3.length = 0;
            r4.length = 0;

        }

    }

});