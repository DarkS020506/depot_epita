//exercice1

// let p1=process.argv[2];
// let p2=process.argv[3];

// if (!p1 || !p2){
//     console.log("erreur");
// }else if (p1.length > p2.length){
//     console.log("plus grand");
// }else if (p1.length < p2.length){
//     console.log("plus petit");
// }else {
//     console.log("egal");
// }

//exercice 2

// let arg=process.argv[2];
// if (!arg){
//     console.log("erreur paramètre manquant");
// }else{
//     const num = parseInt(arg, 10);
//     if (isNaN(num)){
//         console.log("erreur paramètre pas un int");
//     }else{
//         for (let i=1; i<=num ;i++){
//             let output=''
//             for (let y=0; y<i ;y++){
//                 output+='-'
//             }
//             console.log(output);
//         }
//     }
// }


const fs = require('fs-extra');
const express = require('express');
const path = require('path');
fs.writeFileSync('./log.txt', 'Salut !');
fs.appendFileSync('./log.txt', '\nMon texte à la suite');

function onServerStarted() {
    console.log('SERVER STARTED');
}

function onConnection(req, res) {
    const pathOfMyFile = path.resolve('./log.txt');
    res.setHeader('Content-Type', 'text/html');
    res.sendFile(pathOfMyFile);
}

function onDefault(req, res) {
    console.log(req.originalUrl);
    res.status(404);
    res.send('404 not found');
}


const daemon = express();

daemon.get('/', onConnection);
daemon.listen(7542, onServerStarted);
daemon.get(/.*/, onDefault);


