function contar() {
    var txtinicio = window.document.querySelector('input#txtinicio')
    var txtfim = window.document.querySelector('input#txtfim')
    var txtsalto = window.document.querySelector('input#txtsalto')
    
    var inicio = Number(txtinicio.value)
    var fim = Number(txtfim.value)
    var salto = Number(txtsalto.value)

    var res =  window.document.getElementById('res')
    res.innerHTML = null
    console.log(txtfim.value) 

    if (  inicio > fim || fim == 0 || salto == 0) {
        window.alert('Verifique os dados introduzidos!!!')
    }
    else {
        for (inicio; inicio <= fim;inicio += salto){
            res.innerText += `${inicio} 👉`// + String.fromCodePoint(U+1F449)
        }
        res.innerText += '🏁'
    }
    
}