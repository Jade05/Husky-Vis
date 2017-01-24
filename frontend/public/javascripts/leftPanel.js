define(function(require, exports, module) {
        //Return the module value
        return function () {
          // binding events
          $(".pane-left-attribute").click(function(e) {
            var selectAttribute = $(this)[0].name;

            $.post("/selectAttribute"
              , {selectAttribute: selectAttribute}
              , function(result) {
                console.log(result);
            });
          });
        };
    }
);
