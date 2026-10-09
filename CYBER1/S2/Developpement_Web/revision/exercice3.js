const caree=document.getElementById("square")
const bouton=document.getElementById("btn")

bouton.addEventListener("click", function(){
    const nouvelle_ligne=document.createElement("div");
    nouvelle_ligne.style.backgroundColor="white";
    nouvelle_ligne.style.height="2px";
    nouvelle_ligne.style.margin="5px";
    caree.appendChild(nouvelle_ligne);
})