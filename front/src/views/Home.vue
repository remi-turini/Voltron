<template>
  <div class="container-fluid">
    <h1>Données générales</h1>
    <div class="row row-cols-auto justify-content-around mb-5">
      <div>
        <div class="col p-3 mb-2 bg-light d-flex justify-content-center divContent">
          <img src="../assets/Group%2031.png" alt="">
        </div>
        <div class="progress" style="height: 20px;">
          <div class="progress-bar" id="progressHumidity" style="font-size: 14px;" role="progressbar" aria-valuemin="0" aria-valuemax="100"></div>
        </div>
      </div>

      <div>
        <div class="col p-3 mb-2 bg-light d-flex justify-content-center divContent">
          <img src="../assets/Group%2032.png" alt="" >
        </div>
        <div class="progress" style="height: 20px;">
          <div class="progress-bar" role="progressbar" aria-valuemin="0" aria-valuemax="100"></div>
        </div>
      </div>

      <div>
        <div class="col p-3 mb-2 bg-light  d-flex justify-content-center divContent">
          <img src="../assets/Group%2033.png" alt="">
        </div>
        <div class="progress" style="height: 20px;">
          <div class="progress-bar" role="progressbar" aria-valuemin="0" aria-valuemax="100"></div>
        </div>
      </div>

      <div>
        <div class="col p-3 mb-2 bg-light  d-flex justify-content-center divContent">
          <img src="../assets/Group%2024.png" alt="">
        </div>
        <div class="progress" style="height: 20px;">
          <div class="progress-bar" role="progressbar" aria-valuemin="0" aria-valuemax="100"></div>
        </div>
      </div>

    </div>
      <div class="row row-cols-auto justify-content-around">
        <div class="col px-lg-5 bg-light d-flex flex-column justify-content-center divContent">
          <b class="mb-4" style="font-size: 27px">Etat des vignes</b>
          <img src="../assets/Group%2035.png" alt="">
        </div>
        <div class="col px-lg-5 p-3 bg-light  d-flex flex-column justify-content-center divContent">
          <b class="mb-4" style="font-size: 27px; ">Etat du matériel</b>
          <img src="../assets/Group%2030.png" alt="">
        </div>
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
          var e = document.getElementById("progressHumidity"); //Get the element
          e.style.width = newData.data[0].value/5 + "%";
          e.innerHTML = newData.data[0].value/5 + " %";
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
