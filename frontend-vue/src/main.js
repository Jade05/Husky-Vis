// The Vue build version to load with the `import` command
// (runtime-only or standalone) has been set in webpack.base.conf with an alias.
import Vue from 'vue'
import App from './App'
import router from './router'

// 使用 bootstrap
import '@/assets/stylesheets/lib/bootstrap.min.css'

Vue.config.productionTip = false

/* eslint-disable no-new */
new Vue({
  el: '#app',
  router,
  template: '<App/>',
  components: { App },
  data: {
    title: '',
    attributes: [],
    recommendedVis: [],
    selectedVis: []
  },
  created: function () {
    this.fetchSuggestions();
  },
  methods: {
    fetchSuggestions: function () {
      $.get("http://localhost:3005/data", {}, function(result) {
        console.log(result);
        this.title = result.title;
        this.attributes = result.data.attributes;
        this.recommendedVis = result.data.recommendedVis;
        this.selectedVis = result.data.selectedVis;
      });
    }
  }
})
