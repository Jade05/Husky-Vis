<template>
  <div id="app" class="main">
    <h2 class="title">{{title}}</h2>
    <div id="container" class="row">
      <div id="pane-left" class="col-xs-2">
        <router-view name="SelectedList"></router-view>
      </div>
      <div id="pane-right" class="col-xs-10">
        <router-view name="ChartFrame"></router-view>
      </div>
    </div>
  </div>
</template>

<script>
export default {
  name: 'app',
  data () {
      return {title: "Husky-Visualization"}
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
      margin-left: 17%;
    }
  }
}
</style>
