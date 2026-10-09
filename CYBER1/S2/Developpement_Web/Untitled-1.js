let Acteur={
    "prenom":"Will",
    "nom":"Smith",
    "age":39
}
console.log(Acteur);

let acteur2={
    "prenom":"Adam",
    "nom":"Abid",
    "age":18
}

console.log(acteur2)

function creer_acteur(nom, prenom, age){
    this.nom=nom,
    this.prenom=prenom,
    this.age=age
}

let nv_acteur=new creer_acteur("p1", "p2", 20)

class Animal{
    constructor (race, age, patte){
        this.race=race,
        this.age=age,
        this.patte=patte
    }
    appeler(){
        console.log("salut le" + this.race + "qui a" + this.age + " ans et qui as " + this.patte + " pieds")
    }
}

lass Oscar extends Animal{
    constructor(nom, prenom, age, nbroscard)
}
this.nbroscard=nbroscard
