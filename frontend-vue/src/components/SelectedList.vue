<template>
<div id="selected-list">
    <div v-for="attribute in attributes" class="checkbox">
        <label>
            <input class="pane-left-attribute" type="checkbox" :name="attribute" :value="attribute">
            <span class="attribute-name">{{attribute}}</span>
        </label>
    </div>
 </div>
</template>

<script>
export default {
  name: 'SelectedList',
  data () {
    return {attributes: ["Name", "Year", "Month", "Day"]}
  }
}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped lang="less">
.attribute-name {
  margin-left: 10px;
}

.chart-item {
  overflow: scroll;
}
</style>
