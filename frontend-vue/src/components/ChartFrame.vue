<template>
<div>
  <div id="pane-right-selected" class="row">
    <div v-for="(index, item) in selectedVis" class="chart-frame">
      <div v-bind:id="'pane-right-selevted-vis-' + index"class="col-xs-4 chart-item">

      </div>
    </div>
  </div>
  <div id="pane-right-recommended" class="row">
    <div v-for="(index, item) in recommendedVis" class="chart-frame">
      <div v-bind:id="'pane-right-recommended-vis-' + index" class="col-xs-4 chart-item">

      </div>
    </div>
  </div>
</div>
</template>

<script>
export default {
  name: 'ChartFrame',
  props: ['selectedVis', 'recommendedVis']
}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped lang="less">
.chart-item {
  overflow: scroll;
}
</style>
