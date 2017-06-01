<template>
<div>
  <div id="pane-right-selected" class="row">
    <div v-for="(item, index) in selectedVis" class="chart-frame">
      <div v-bind:id="'pane-right-selected-vis-' + index" class="col-xs-4 chart-item"></div>
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
  props: ['selectedVis', 'recommendedVis']
}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped lang="less">
/* for webkit */
/* 设置滚动条的样式 */
::-webkit-scrollbar {
  width: 5px;
  height: 5px;
}

/* 滚动槽 */
::-webkit-scrollbar-track {
  box-shadow: inset 0 0 6px rgba(0,0,0,0.3); 
  border-radius: 2px;
}
 
/* 滚动条滑块 */
::-webkit-scrollbar-thumb {
  border-radius: 2px;
  background: rgba(0,0,0,0.1); 
  -webkit-box-shadow: inset 0 0 6px rgba(0,0,0,0.5); 
}
::-webkit-scrollbar-thumb:window-inactive {
  background: rgba(0,0,0,0.1); 
}
::-webkit-scrollbar-thumb:hover{
  background-color:rgba(255,0,0,0.4);
  -webkit-border-radius:4px;
}
.chart-item {
  overflow: scroll;
  height: 320px;
}
</style>
