var connect = require("./connect");

connect.init();

connect.get_suggestions(function(response) {
    console.log(response);
});

