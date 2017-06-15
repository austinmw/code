/*

EC544 Group 4

Challenge 2

Visualize Temperature Data

*/

/* ----------- Declare Dependencies ------------ */

var SerialPort = require("serialport");
var express = require('express');
app = express();
var http = require('http').Server(app);
var io = require('socket.io')(http);
var ON_DEATH = require('death');


var datetime = new Date();

app.get('/', function(req, res){
  res.sendFile('/Users/jmeunier28/Desktop/EC544/challenges/EC544/challengeTwo/public/index.html');
});
app.get('/current', function(req,res){
  res.sendFile('/Users/jmeunier28/Desktop/EC544/challenges/EC544/challengeTwo/public/Current-Reading.html');
});
app.get('/historic',function(req,res){
  res.sendFile('/Users/jmeunier28/Desktop/EC544/challenges/EC544/challengeTwo/public/Historic-View.html');
});

app.use(express.static(__dirname + '/public'));

/*----------- Connecting to Mongo --------------- */

var MongoClient = require('mongodb').MongoClient;
var assert = require('assert');
var ObjectId = require('mongodb').ObjectID;
var url = 'mongodb://localhost:27017/challengeTwo';

MongoClient.connect(url, function (err, db) {
  if (err) {
    console.log('Unable to connect to the mongoDB server. Error:', err);
  } else {
    
    console.log('Connection established to', url);


    //Close connection
    //db.close();
  }
});

/* ------------- Connecting to Serial Port ---------------- */

var portName = '/dev/cu.usbserial-AD01SSII',
portConfig = {
  baudRate: 9600,
  parser: SerialPort.parsers.readline("\n")
};


/* ------------ Error Handling ---------------*/

//catch 404 and forward to error handler
app.use(function(req, res, next) {
  var err = new Error('Not Found');
  err.status = 404;
  next(err);
});

// error handlers

// development error handler
// will print stacktrace
if (app.get('env') === 'development') {
  app.use(function(err, req, res, next) {
    res.status(err.status || 500);
    res.render('error', {
      message: err.message,
      error: err
    });
  });
}

// production error handler
// no stacktraces leaked to user
app.use(function(err, req, res, next) {
  res.status(err.status || 500);
  res.render('error', {
    message: err.message,
    error: {}
  });
});

/* -----Run App on LocalHost Port 3000----- */

http.listen(3000, function(){
  console.log('listening on *:3000');
});

/* ------------- App Logic ------------ */


var sp;
sp = new SerialPort.SerialPort(portName, portConfig);


//can also create other html page to render

  sp.on("open", function (err) {
    if (err) 
      return console.log('Error opening port: ', err.message);
    console.log('open');
    
    // INFO VARIABLES
    var connectedNodes = [];
    var buffer0;
    var nodeInfo; 
    var nodesArray = [[0,0,0]]; // remember that length is +1
    var numNodes = 0;
    
    // Cleanup when termination signals are sent to process
    ON_DEATH(function(signal, err) {
      var death_msg = "Q";
      sp.write(death_msg);
      sp.close();   
      console.log("\n\nSending reset signal to nodes.\n\n")
      process.exit();
    })
    
    
    // Check for and remove old nodes
    var CheckNodes = function() {
      var time = new Date();  
      var nodeCount = nodesArray.length - 1;
      for (var i = 1; i <= numNodes; i++) {
        var t = time.getTime();
        var timeDiff = t - nodesArray[i][2]; 
        if (timeDiff > 2200) {
            // remove node's subarray
            console.log("Removing stale node " + nodesArray[i][0])
            nodesArray.splice(i, 1);
            numNodes--;
            //console.log("numNodes: " + numNodes);
        }
      } }
    setInterval(function(){ CheckNodes() }, 600); 
    // 2100+300 (check) < 2500 (avg) > 2000 (xmit)
    // looks like these times work  

      var CalcAverage = function() {
      var tempSum = 0;
      var nodeCount = nodesArray.length - 1;
      for (var i = 1; i <= nodeCount; i++) {
        // Make sure value in temp index is a number
        if (!isNaN(parseFloat(nodesArray[i][1]))) {
          tempSum += parseFloat(nodesArray[i][1]);
        }
      }
      var tempAverage = tempSum / numNodes;
      //console.log("nodeCount: " + nodeCount);
      //console.log("tempSum: " + tempSum); 
      if (!isNaN(tempAverage)) {
        console.log("\nNode count: " + nodeCount + "   Average temperature: " + tempAverage.toFixed(2) + "F");
        io.emit('chat message',tempAverage.toFixed(2));       
        for (var j = 1; j <= numNodes; j++) {
          console.log("  " + ("     " + nodesArray[j][0]).slice(-7) + " : " + nodesArray[j][1] + "F")   
        }
      }
      if (numNodes == 0) {
        console.log("No nodes currently connected. Waiting for connection . . .")
      } 
      MongoClient.connect(url, function (err, db) {
        if (err) {
          console.log('Unable to connect to the mongoDB server. Error:', err);
        } else {
          
          console.log('Connection established to', url);

          var document = {"Time": (new Date().getTime() - datetime.getTime()) / 1000, "Temp": tempAverage};

          //insert record
          db.collection('challengeTwo').insert(document, function(err, records) {
            if (err) throw err;
            //console.log("Record added as "+records[0]._id);
            console.log("Insert Avg Temp into challengeTwo collection");
         });

          //Close connection
          //db.close();
        }
      });

    }
    
    setInterval(function(){ CalcAverage() },2500);
 

    //var data = {"Temp": tempAvg, "Time": datetime.getTime()};

io.on("connection",function(socket){
  
  console.log('a user connected');
  
  socket.on('buttonPress',function(string){
    
    console.log("button pressed drawing graph..");
  MongoClient.connect(url,function(err,db){
      //console.log("made mongo conn");
      var str = null;
      var cursor =db.collection('challengeTwo').find({});
      cursor.each(function(err, doc) { //get each data point in DB
          assert.equal(err, null);
          if (doc != null) {
            
             str= [doc.Time, doc.Temp];
             console.log("not null" + str);
            socket.broadcast.emit('msg',str);
              socket.emit('msg',str);

          } else {
            console.log(str);
            str = null;
            //socket.emit('msg',str);
            console.log("null" + str);
               
             //callback();
          }

        }); 

      }); //end mongo client

  }); //end socket.on
});// end io.on

    
    // listen for data, grab temp & time, populate array
    sp.on('data', function(data) {
      sp.flush();
      var time = new Date();  
      buffer0 = data.split('\n'); // array of data till newline
      // Split again into either [#ID] or [#ID, Data] 
      nodeInfo = buffer0[0].split('   ');
      // Receiving good data ( ID or [ID, Data] )
      if (nodeInfo[0][0] == "#") { // could check up here for && no temp data too 
        
        // New node
        if (connectedNodes.indexOf(nodeInfo[0]) == -1) {
          CheckNodes();
          var dumNum = numNodes + 1;
          console.log("\n (" + dumNum + ") NEW CONNECTION: Sending handshake confirmation to: " + nodeInfo[0])
          connectedNodes.push(nodeInfo[0]);     
          sp.write(nodeInfo[0]);
        }
        
        // Preconnected node
        else if (connectedNodes.indexOf(nodeInfo[0]) != -1) {
          currentTime = time.getTime();
          //console.log("  Connected node: " + nodeInfo[0] + "   " + nodeInfo[1]);
      
          // If node has temp data: [ID, Temp]
          if (typeof nodeInfo[1] != 'undefined') {
        
            // Go through Nx3 array, see if this node ID is in nodesArray
            var foundAtIndex;
            for (var i = 0; i < nodesArray.length; i++)  {
              // If found ID
              if (nodesArray[i].indexOf(nodeInfo[0]) != -1) {
                foundAtIndex = i;
                break;
              } 
            }
            // Push [ID, Temp, Time] to nodesArray if ID doesn't exist within it
            if (typeof foundAtIndex === 'undefined') {
              numNodes++;
              //console.log("added to nodesArray") // debug print statement
              var idTempTime = [nodeInfo[0], nodeInfo[1], currentTime]; 
              nodesArray.push(idTempTime);
            } 
            // Update Temp, Time if ID already exists in nodesArray
            else {
              nodesArray[foundAtIndex][1] = nodeInfo[1];
              nodesArray[foundAtIndex][2] = currentTime;
              //console.log("  updated time/temp") // debug print statement
            }
          }
        } 
      }
      // Bad data coming in
      else if (nodeInfo[0][0] != "#") {
        // FOR DEBUGGING PURPOSES, DELETE LATER
        console.log("Corrupted node data. Push reconnect button if not already connected.")
      }
    // return the calulated average 
 
    }); // end data

  }); // end open

//db.close(); //close connection 
