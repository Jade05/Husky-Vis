<template>
<div>
  <div id="pane-right-selected" class="row">
    <div v-for="(index, item) in selectedVis" class="chart-frame">
      <div v-bind:id="'pane-right-selevted-vis-' + index" class="col-xs-4 chart-item">

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
<div id="chat" v-chat="{flower: true, image: false}">world</div>
</template>

<script>
Vue.directive('chat', function (value) {
    console.log(this.el); //world
    console.log(this.arg);          //hello
    console.log(this.name);         //chat
    console.log(this.expression);   //msg
});

export default {
  name: 'ChartFrame',
  props: ['selectedVis', 'recommendedVis'],
  created () {
    console.log('created')
    console.log($('.chart-item'))
  },
  mounted () {
    console.log('mounted')
    console.log($('.chart-item'))
  },
  methods: {
    renderCharts () {
      console.log('renderCharts')
      console.log($('.chart-item'))
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
