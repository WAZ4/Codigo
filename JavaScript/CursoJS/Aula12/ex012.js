var horaAtual = new Date()
var hora = horaAtual.getHours()
console.log(`Agora sao ${hora}`)
if (hora <12) {
    console.log('Bom dia')
}
else if(hora <= 18){
    console.log('Boa Tarde')
}
else {
    console.log('Boa Noite')
}