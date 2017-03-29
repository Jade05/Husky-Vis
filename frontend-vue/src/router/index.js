import Vue from 'vue'
import Router from 'vue-router'
import SelectedList from '@/components/SelectedList'
import ChartFrame from '@/components/ChartFrame'

Vue.use(Router)

export default new Router({
    routes: [
        {
            path: '/',
            components: {
              SelectedList: SelectedList,
              ChartFrame: ChartFrame
            }
        }
    ]
})
