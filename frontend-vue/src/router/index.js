import Vue from 'vue'
import Router from 'vue-router'
import Hello from '@/components/Hello'
import SelectedList from '@/components/SelectedList'

Vue.use(Router)

export default new Router({
    routes: [
        {
            path: '/',
            name: 'Hello',
            component: Hello
        },
        {
            path: '/test',
            name: '',
            component: SelectedList
        }
    ]
})
