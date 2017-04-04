<template>
<div>
  <div id="pane-right-selected" class="row">
    <div v-for="(item, index) in selectedVis" class="chart-frame">
      <div v-bind:id="'pane-right-selevted-vis-' + index" class="col-xs-4 chart-item"></div>
    </div>
  </div>
  <div id="pane-right-recommended" class="row">
    <div v-for="(item, index) in recommendedVis" class="chart-frame">
      <div v-bind:id="'pane-right-recommended-vis-' + index" class="col-xs-4 chart-item"></div>
    </div>
  </div>
</div>
</template>

<script>
import Vue from 'vue'

export default {
  name: 'ChartFrame',
  props: ['selectedVis', 'recommendedVis'],
  mounted () {
    this.triggerRenderCharts();
  },
  methods: {
    triggerRenderCharts () {
      // this.$nextTick(function() {
      //   console.log($('#pane-right-recommended .chart-item'))
      //   console.log("hahahah")
      // })
      // this.$nextTick(() => {
      //   // console.log($("#pane-right-recommended-vis-0"))
      //   // emit
      //   this.$emit('renderChartsEvent', {
      //     $selectedVisItem: $("#pane-right-selected"),
      //     $recommendedVisItem: $('pane-right-recommended .chart-item'),
      //     $test: $('#pane-right')
      //   });
      // });
    }
  }
}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped lang="less">
.chart-item {
  overflow: scroll;
}
</style>
