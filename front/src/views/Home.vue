<template>
  <div class="container-fluid">
    <h1 class="mb-5">Données générales</h1>
    <div class="d-flex flex-column mb-4" v-for="sensor in sensors" :key="sensor.id">
      Type de capteur : {{sensor.type}}
      Valeur du capteur : {{sensor.value}}
    </div>
  </div>
</template>

<script>
export default {
  name: "App",
  data() {
    return {
      sensors: {},
    };
  },
  created() {
    this.getSensors();
  },
  methods: {
    async getSensors() {
      try {
        const requestOptions = {
          method: "GET",
          headers: {
            "Content-Type": "application/json"
          },
        };
        var url2 = "http://localhost:3001/sensors";
        requestOptions;
        const res1 = await fetch(url2, requestOptions);
        const data1 = await res1.json();
        if (data1.state == "ok") {
          var newData = JSON.parse(JSON.stringify(data1));
          this.sensors = newData.data;
        } else {
          console.log(data1.message);
        }
      } catch (error) {
        console.log(error);
      }
    }
  }
}
</script>

<style scoped>


</style>
