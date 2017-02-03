define(function(require, exports, module) {
        var visualization = require('visualization');

        //Return the module value
        return function () {
          // binding events
          $(".pane-left-attribute").click(function(e) {
            var selectAttribute = $(this)[0].name;

            $.post("/selectAttribute"
              , {selectAttribute: selectAttribute}
              , function(result) {
                // reset the right panel
                if (result) {
                    $('#pane-right').html(result.html);
                    // visualize the right panel
                    visualization(result.data.data);
                } else {
                  console.log('selectAttribute failed!');
                }
            });
          });
        };
    }
);
