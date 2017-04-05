var connect = require("./connect");

connect.init();

var response;
connect.get_suggestions(function(response) {
    console.log(response);
});


//connect.get_attributes(function(response) {
//    console.log(response);
//});
