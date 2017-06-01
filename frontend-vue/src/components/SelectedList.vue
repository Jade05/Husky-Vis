<template>
<div id="selected-list" v-on:change="triggerSelectedListEvent">
    <div v-for="attribute in attributes" class="radio-list">
        <label>
            <!-- about this part, it is suitable for single radio selected not for multiple choices
            if you want to use multiple choices, use checkbox instead-->
            <input class="pane-left-attribute" type="radio" :name="attribute" :value="attribute" v-model="picked"  checked="checked">
            <span class="attribute-name">{{attribute}}</span>
        </label>
    </div>
 </div>
</template>

<script>
export default {
  name: 'SelectedList',
  data () {
    return {
      picked: ''
    }
  },
  props: ['attributes'],
  methods: {
    triggerSelectedListEvent () {
      // emit parent component to process the event
      this.$emit('selectedListEvent', this.picked);
    }
  }
}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped lang="less">
.attribute-name {
  margin-left: 10px;
}

.chart-item {
  overflow: auto;
}
</style>
