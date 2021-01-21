const dino = document.querySelector('.dino');
const background = document.querySelector('.background');
let isJumping = false;
let position = 0;
let gameOver = false;

//console.log("dino");
//console.log(dino);
//<div class="dino"></div>

/* document.addEventListener('keyup', function(){
  console.log('pressionou uma tecla');
}); */

function handleKeyUp(event){
  if(event.keyCode === 32){
    if(!isJumping){
      jump();
    }
    
    //console.log('pressionou espaco')
  }
}

function jump(){
  isJumping = true;

  let upInterval = setInterval(() => {
    if(position >= 150){
      //150 pixels
      clearInterval(upInterval);
      
      //descendo
      let downInterval = setInterval(() =>{
        if(position <= 0){
          clearInterval(downInterval);
          isJumping = false;
        }else{
          position = position - 20;
          dino.style.bottom = position + 'px';  
        }

      }, 20);
    }else{

    }
    //funcao nativa que faz repetir o codigo aqui
    //a cada 20 milisegundos
    position = position + 20;
    dino.style.bottom = position + 'px';
  }, 20);

}

function createCactus(){
  const cactus = document.createElement('div');
  let cactusPosition = 1000;
  let randomTime = Math.random() * 6000;
    //gera numero aleatorio de 0 a 1
  // console.log(randomTime);

  cactus.classList.add('cactus');
  cactus.style.left = 1000 + 'px';
  
  background.appendChild(cactus);

  let leftInterval = setInterval(() =>{

    if(cactusPosition < -60){
      clearInterval(leftInterval);
      background.removeChild(cactus);
    }else if(cactusPosition > 0 && cactusPosition < 60 && position < 60){
      //game over
      clearInterval(leftInterval);
      document.body.innerHTML = '<h1 class="game-over">Fim de jogo</h1>';
      gameOver = true;
    } else{  
    cactusPosition = cactusPosition - 10;
    cactus.style.left = cactusPosition + 'px';
    }

    //otimo lugar para aumentar a dificuldade durante a partida
  }, 20);
  if(gameOver === false){
    setTimeout(createCactus, randomTime);
  }
  
}

createCactus();
document.addEventListener('keyup', handleKeyUp);