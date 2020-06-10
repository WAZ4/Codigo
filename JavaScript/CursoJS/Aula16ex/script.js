var dados = []

//funcoes auxiliares

function verificar_dados(num) {
    
    for (let i = 0; i < dados.length; i++) {
        if (num == dados[i]) {
            return 1
        }
    }
    
    return 0
}

function extremo(opcao) {
    let extremo = dados[0]

    if (opcao == 'Maior') {   
        for(let i in dados) {
            if (extremo < dados[(i)]) {
                extremo = dados[i]
            }
        }
        return extremo
    }
    else if (opcao == 'Menor') {
        for(let i in dados) {
            if (extremo > dados[(i)]) {
                extremo = dados[i]
            }
        }
        return extremo
    }
    else {
        return -1
    }
}

function soma() {
    let res = 0

    for (let i in dados) {
        res += dados[i]
    }

    return res

}

function media() {
    let res = 0;

    for (let i in dados) {
        res += dados[i]
    }

    return (res/dados.length)
}

// funcoes principais

function adicionar_numero() {
    let txtnum = window.document.getElementById('txtnum')
    let num = Number(txtnum.value)
    let lista = window.document.getElementById('lista')
    let res = window.document.getElementById('res')

    let novoNumero = document.createElement('option')
    
    res.innerHTML = ''

    if (txtnum === '' || num < 1 || num > 100 || verificar_dados(num) === 1) {
        window.alert('Por favor verifique os dados!!!')
    }
    else {
        novoNumero.innerText = `Numero ${num} adicionado`
        dados.push(num)

        lista.appendChild(novoNumero)
    }
}




function calcular_resultados() {
    let res = window.document.getElementById('res')


    if (dados.length != 0) {

    res.innerHTML = `<p> O total de numeros inseridos e de ${dados.length}
                    <br> O maior valor inserido foi ${extremo('Maior')}
                    <br> O menor valor inserido foi ${extremo('Menor')}
                    <br> A soma de todos os valores da ${soma()}
                    <br> A media de todos os valores e ${media()}
                    </p>`
    }
    else {
        window.alert('E necessario introduzir numeros antes de calcular!!!')
    }
    
}