<script setup>
import { RouterLink, RouterView } from 'vue-router'
</script>

<template>
  <header>
      <nav>
        <div class="container-fluid">
          <div class="row flex-nowrap">
            <div class="col-auto col-md-3 col-xl-2 px-sm-2 px-0 border-end">
              <div class="d-flex flex-column align-items-center align-items-sm-start px-3 pt-2 min-vh-100">
                <div class="d-flex align-items-center pb-3 mb-md-0 me-md-auto text-decoration-none">
                  <p class="h4 d-none d-sm-inline">Mon espace Vigneron</p>
                </div>
                <ul class="nav nav-pills flex-column mb-sm-auto mb-0 align-items-center align-items-sm-start" id="menu">
                  <li class="nav-item">
                    <RouterLink to="/" class="nav-link align-middle px-0 router-link">
                      <img class="icon-purple" src="./assets/home-purple.png" alt="" style="width: 30px;"><img class="icon-white" src="./assets/home-white.png" alt="" style="width: 30px;"><span class="ms-1 d-none d-sm-inline">Accueil</span>
                    </RouterLink>
                  </li>
                  <li class="nav-item">
                    <RouterLink to="/sick" class="nav-link align-middle px-0 router-link">
                      <img class="icon-purple" src="./assets/home-purple.png" alt="" style="width: 30px;"><img class="icon-white" src="./assets/home-white.png" alt="" style="width: 30px;"><span class="ms-1 d-none d-sm-inline">Evolution des maladies</span>
                    </RouterLink>
                  </li>
                  <li class="nav-item">
                    <RouterLink to="/result" class="nav-link align-middle px-0 router-link">
                      <img class="icon-purple" src="./assets/home-purple.png" alt="" style="width: 30px;"><img class="icon-white" src="./assets/home-white.png" alt="" style="width: 30px;"><span class="ms-1 d-none d-sm-inline">Résultat</span>
                    </RouterLink>
                  </li>
                  <li class="nav-item">
                    <RouterLink to="/culture" class="nav-link align-middle px-0 router-link">
                      <img class="icon-purple" src="./assets/home-purple.png" alt="" style="width: 30px;"><img class="icon-white" src="./assets/home-white.png" alt="" style="width: 30px;"><span class="ms-1 d-none d-sm-inline">Mes cultures</span>
                    </RouterLink>
                  </li>
                  <li class="nav-item">
                    <RouterLink to="/profil" class="nav-link align-middle px-0 router-link">
                      <img class="icon-purple" src="./assets/home-purple.png" alt="" style="width: 30px;"><img class="icon-white" src="./assets/home-white.png" alt="" style="width: 30px;"><span class="ms-1 d-none d-sm-inline">Profil</span>
                    </RouterLink>
                  </li>
                </ul>
              </div>
            </div>
            <div class="col py-3">
              <RouterView />
            </div>
          </div>
        </div>
      </nav>
  </header>
</template>

<script>
export default {
  name: "App",
  data: () => {
    return {
      active: false,
      bearer: localStorage.bearer,
    };
  }
}
</script>

<style>
a{
  text-decoration: none !important;
  color: #B87DD6 !important;
}
.router-link:hover {
  background-color: #B87DD6;
  color: white;
}

.router-link.router-link-active .icon-purple {
  display: none;
}
.router-link.router-link-active .icon-white {
  display: inline-block;
}
.router-link.router-link-active{
  background-color: #B87DD6 !important;
  color: white !important;
}
.router-link .icon-purple {
  display: inline-block;
}
.router-link .icon-white {
  display: none;
}

.router-link img{
  margin-left: 10px;
  margin-right: 10px;
}
.router-link{
  padding: 10px 20px;
  border-radius:15px !important;
}
.nav-item{
  width: 270px;
}

</style>
