
void sendIr(unsigned long to_send) {
  irsend.sendSony(to_send, 12);
  delay(50);  
}

