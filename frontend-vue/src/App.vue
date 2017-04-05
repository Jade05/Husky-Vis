<template>
  <div id="app" class="main">
    <h2 class="title">{{title}}</h2>
    <div id="container" class="row">
      <div id="pane-left" class="col-xs-2">
        <router-view :attributes="attributes" name="SelectedList" @selectedListEvent="selectedList"></router-view>
      </div>
      <div id="pane-right" class="col-xs-10">
        <router-view :selectedVis="selectedVis" :recommendedVis="recommendedVis" name="ChartFrame"></router-view>
      </div>
    </div>
  </div>
</template>

<script>
import Vue from 'vue'

export default {
  name: 'app',
  data () {
    return {
      title: '',
      attributes: [],
      selectedVis: [],
      recommendedVis: []
    }
  },
  created () {
    this.fetchSuggestions({}, 'http://localhost:3000/');
  },
  mounted () {
  },
  methods: {
    fetchSuggestions (params, url) {
      let vm = this;
      $.get(url, params, (result) => {
        // object destruction
        [
          vm.title,
          vm.attributes,
          vm.recommendedVis,
          vm.selectedVis
        ] = [
          result.title,
          result.data.attributes,
          result.data.recommendedVis,
          result.data.selectedVis
        ];

        // renderCharts
        vm.$nextTick(function() {
          vm.renderCharts();
        });
      });
    },
    renderCharts () {
      // rencer selectedCharts
      this.render(this.selectedVis, '#pane-right-selected-vis-');
      // render recommendedChart
      this.render(this.recommendedVis, '#pane-right-recommended-vis-');
    },
    render (data, idPrefix) {
      let index = 0;
      for (let item of data) {
        let embedSpec = {
          mode: 'vega-lite',
          spec: item
        };

        vg.embed(idPrefix.toString() + index, embedSpec, (error, result) => {if (error) console.log(error)});
        index++;
      }
    },
    selectedList (pickedItem) {
      let params = {
        picked: pickedItem
      };
      this.fetchSuggestions(params, 'http://localhost:3000/selectAttribute');
    }
  }
}
</script>

<style lang="less">
.main {
  font-size: 14px;

  .title {
    font-size: 20px;
    height: 40px;
    line-height: 40px;
    margin-left: 10px
  }

  #container {
    #pane-left {
      position: absolute;
      top: 40px;
      bottom: 0;
      left: 0;
      right: 0;
      background-color: #428bca;
      padding: 15px 0 15px 25px;
    }
    #pane-right {
      margin-left: 18%;
    }
  }
}
</style>
