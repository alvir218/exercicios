//programador: allan stuart virmond
//professor: fernando maia
//instituicao de ensino: colegio estadual do parana
//disciplina: linguagem de programacao
//ide: visualg.2
//data: 09.06.2018

//exercicio: 
//calculo de autonomia de automoveis
//determina quantas paradas para reabastecimento durante uma viagem


algoritmo "autonomiaveicular"

  var
    mediadeconsumo,distanciaapercorrer,capacidadedotanque,autonomiamaxima:real
    pergunta1,pergunta2:inteiro

  inicio
    escreval("C�lculo de autonomia veicular:")
    escreval
    escreval

    repita

      escreval
      escreval("Voc� sabe a m�dia de consumo de seu ve�culo?")
      escreval("1 - N�o.")
      escreval("2 - Sim.")
      escreval
      leia(pergunta1)

    ate (pergunta1=1) ou (pergunta1=2)

    se pergunta1 = 1 entao
      escreval
      escreval("Escolha o tipo de ve�culo mais parecido com o seu:")
      escreval
      escreval("1 - Carro de baixo consumo como: Gol, Uno ou Clio (a Alcool)")
      escreval("2 - Carro de baixo consumo como: Gol, Uno ou Clio (a Gasolina)")
      escreval("3 - Carro de consumo m�dio como: Santana, Vectra, Siena (a Alcool)")
      escreval("4 - Carro de consumo m�dio como: Santana, Vectra, Siena (a Gasolina)")
      escreval("5 - Carro de alto consumo como: Opala, Maverick")
      escreval("6 - SUV (a Alcool)")
      escreval("7 - SUV (a Gasolina)")
      escreval("8 - Caminhonete (a Alcool)")
      escreval("9 - Caminhonete (a Gasolina)")
      escreval("10 - Caminhonete (a Diesel)")
      escreval("11 - Caminh�o descarregado (a Diesel)")
      escreval("12 - Carreta (a Diesel)")
      escreval("13 - Carreta bitrem (a Diesel)")
      escreval("14 - Onibus (a Diesel)")
      escreval("15 - Onibus articulado (a Diesel)")
      escreval("16 - Onibus biarticulado (a Diesel)")
      escreval

      repita

        leia(pergunta2)
        escolha pergunta2
          caso 1
            mediadeconsumo <- 7.5
            escreval("Considerando a media de consumo em",mediadeconsumo," Quil�metros por Litro.")
          caso 2
            mediadeconsumo <- 11.4
            escreval("Considerando a media de consumo em",mediadeconsumo," Quil�metros por Litro.")
          caso 3
                mediadeconsumo <- 7.7
                escreval("Considerando a media de consumo em",mediadeconsumo," Quil�metros por Litro.")
          caso 4
                mediadeconsumo <- 11.1
                escreval("Considerando a media de consumo em",mediadeconsumo," Quil�metros por Litro.")
          caso 5
                mediadeconsumo <- 6
                escreval("Considerando a media de consumo em",mediadeconsumo," Quil�metros por Litro.")
          caso 6
                mediadeconsumo <- 7.1
                escreval("Considerando a media de consumo em",mediadeconsumo," Quil�metros por Litro.")
          caso 7
                mediadeconsumo <- 10.5
                escreval("Considerando a media de consumo em",mediadeconsumo," Quil�metros por Litro.")
          caso 8
                mediadeconsumo <- 5.53
                escreval("Considerando a media de consumo em",mediadeconsumo," Quil�metros por Litro.")
          caso 9
                mediadeconsumo <- 9.3
                escreval("Considerando a media de consumo em",mediadeconsumo," Quil�metros por Litro.")
          caso 10
                mediadeconsumo <- 8.9
                escreval("Considerando a media de consumo em",mediadeconsumo," Quil�metros por Litro.")
          caso 11
                mediadeconsumo <- 5
                escreval("Considerando a media de consumo em",mediadeconsumo," Quil�metros por Litro.")
          caso 12
                mediadeconsumo <- 2.5
                escreval("Considerando a media de consumo em",mediadeconsumo," Quil�metros por Litro.")
          caso 13
                mediadeconsumo <- 2.35
                escreval("Considerando a media de consumo em",mediadeconsumo," Quil�metros por Litro.")
          caso 14
                mediadeconsumo <- 2.38
                escreval("Considerando a media de consumo em",mediadeconsumo," Quil�metros por Litro.")
          caso 15
                mediadeconsumo <- 1.2
                escreval("Considerando a media de consumo em",mediadeconsumo," Quil�metros por Litro.")
          caso 16
                mediadeconsumo <- 0.8
                escreval("Considerando a media de consumo em",mediadeconsumo," Quil�metros por Litro.")
          outrocaso
            escreval
            escreval("Por favor informe um n�mero correspondente ao seu tipo de ve�culo.")
            escreval
        fimescolha

      ate (pergunta2 = 1) ou (pergunta2 = 2) ou (pergunta2 = 3) ou (pergunta2 = 4) ou (pergunta2 = 5) ou (pergunta2 = 6) ou (pergunta2 = 7) ou (pergunta2 = 8) ou (pergunta2 = 9) ou (pergunta2 = 10) ou (pergunta2 = 11) ou (pergunta2 = 12) ou (pergunta2 = 13) ou (pergunta2 = 14) ou (pergunta2 = 15) ou (pergunta2 = 16)

    senao
      se pergunta1 = 2 entao
        escreval
        escreval("Quantos Quil�metros percorre seu ve�culo com 1 Litro de combust�vel?")
        escreval
        leia(mediadeconsumo)
      fimse
    fimse
    escreval
    escreval("Qual � a capacidade total do seu tanque de combust�vel em Litros?")
    escreval
    leia(capacidadedotanque)
    autonomiamaxima <- (mediadeconsumo*capacidadedotanque)
    escreval
    escreval("Qual � a dist�ncia da viagem em Quil�metros?")
    escreval
    leia(distanciaapercorrer)
    se distanciaapercorrer > autonomiamaxima entao
      escreval
      escreval("Voc� precisar� fazer",distanciaapercorrer/autonomiamaxima," paradas para abastecer nessa viagem.")
      escreval
    senao
      se distanciaapercorrer <= autonomiamaxima entao
        escreval
        escreval("Voc� pode fazer essa viagem sem parar para abastecer.")
        escreval
      fimse
    fimse
fimalgoritmo
