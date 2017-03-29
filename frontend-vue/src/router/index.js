import Vue from 'vue'
import Router from 'vue-router'
import SelectedList from '@/components/SelectedList'

Vue.use(Router)

export default new Router({
    routes: [
        {
            path: '/',
            name: '',
            component: SelectedList
        }
    ]
})
