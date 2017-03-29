<template>
    <div id="app">
        <h2 class="title">{{title}}</h2>
        <div id="container" class="row">
            <div id="pane-left" class="col-xs-2">
                <router-view></router-view>
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

<style>
#app {
  font-family: 'Avenir', Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin-top: 60px;
}
</style>
