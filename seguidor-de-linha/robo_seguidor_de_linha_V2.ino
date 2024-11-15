const int sensorEsquerdo = 5;
const int sensorDireito = 6;

const int motorEsquerdoFrente = 10;
const int motorEsquerdoTras = 11;
const int motorDireitoFrente = 12;
const int motorDireitoTras = 13;

const int velocidade = 90; // 0 a 255

void setup() {
  pinMode(sensorEsquerdo, INPUT);
  pinMode(sensorDireito, INPUT);

  pinMode(motorEsquerdoFrente, OUTPUT);
  pinMode(motorEsquerdoTras, OUTPUT);
  pinMode(motorDireitoFrente, OUTPUT);
  pinMode(motorDireitoTras, OUTPUT);

  pararMotores();
}

void loop() {
  int leituraEsquerda = digitalRead(sensorEsquerdo);
  int leituraDireita = digitalRead(sensorDireito);

  if (leituraEsquerda == LOW && leituraDireita == LOW) {
    // Ambos os sensores detectam a linha -> seguir em frente
    moverFrente();
  } else if (leituraEsquerda == LOW && leituraDireita == HIGH) {
    // Somente o sensor esquerdo detecta a linha -> virar para a esquerda
    virarEsquerda();
  } else if (leituraEsquerda == HIGH && leituraDireita == LOW) {
    // Somente o sensor direito detecta a linha -> virar para a direita
    virarDireita();
  } else {
    // Nenhuma detecção -> parar
    pararMotores();
  }
}

void moverFrente() {
  analogWrite(motorEsquerdoFrente, velocidade);
  analogWrite(motorEsquerdoTras, 0);
  analogWrite(motorDireitoFrente, velocidade);
  analogWrite(motorDireitoTras, 0);
}

void virarEsquerda() {
  analogWrite(motorEsquerdoFrente, 0);
  analogWrite(motorEsquerdoTras, 0);
  analogWrite(motorDireitoFrente, velocidade);
  analogWrite(motorDireitoTras, 0);
}

void virarDireita() {
  analogWrite(motorEsquerdoFrente, velocidade);
  analogWrite(motorEsquerdoTras, 0);
  analogWrite(motorDireitoFrente, 0);
  analogWrite(motorDireitoTras, 0);
}

void pararMotores() {
  analogWrite(motorEsquerdoFrente, 0);
  analogWrite(motorEsquerdoTras, 0);
  analogWrite(motorDireitoFrente, 0);
  analogWrite(motorDireitoTras, 0);
}
