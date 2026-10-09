const caree= document.getElementById("square");
let position_largeur=0;
let position_hauteur=0;
let direction_largeur=5;
let direction_hauteur=5;
function deplacer(){
    position_largeur=position_largeur+(2*direction_largeur);
    position_hauteur=position_hauteur+(2*direction_hauteur);
    caree.style.left=position_largeur+"px"
    caree.style.top=position_hauteur+"px"
    if (position_largeur>=450){
        direction_largeur=-5;
    }
    if (position_largeur<=0){
        direction_largeur=5;
    }
    if (position_hauteur>=250){
        direction_hauteur=-5;
    }
    if (position_hauteur<=0){
        direction_hauteur=5;
    }
}
setInterval(deplacer, 1);