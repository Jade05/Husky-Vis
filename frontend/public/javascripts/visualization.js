define(function(require, exports, module) {
        //Return the module value
        return function (suggestions) {
          // visualize selectedVis
          for (var i = 0; i < suggestions.selectedVis.length; i++) {
            var embedSpec = {
              mode: "vega-lite",  // Instruct Vega-Embed to use the Vega-Lite compiler
              spec: suggestions.selectedVis[i]
            };
            // Embed the visualization in the container with id `vis`
            var visId = "#pane-right-selevted-vis-" + i;
            vg.embed(visId, embedSpec, function(error, result) {
              
            });
          }
          // visualize recommendeddVis
          for (var i = 0; i < suggestions.recommendedVis.length; i++) {
            var embedSpec = {
              mode: "vega-lite",  // Instruct Vega-Embed to use the Vega-Lite compiler
              spec: suggestions.recommendedVis[i]

            };
            // Embed the visualization in the container with id `vis`
            var visId = "#pane-right-recommended-vis-" + i;
            // console.log(suggestions.recommendedVis[i]);
            vg.embed(visId, embedSpec, function(error, result) {

            });
          }
        };
    }
);
