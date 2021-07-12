

"use strict";
const Queue = require('./Queue.js');
const Stack = require('./Stack.js');

function reverse(queue, k){
  if(k === 0) return;
  var ele = queue.getFront();
  queue.dequeue();
  reverse(queue, k-1);
  queue.enqueue(ele);
}


function reverseK(queue,k){
  if(k === 0) return queue;
  if(queue.size() === k) reverse(queue, k);
  else{
    reverse(queue, k);
    for(var i = 0; i < queue.size()-k; i++){
      queue.enqueue(queue.getFront());
      queue.dequeue();
    }
  }
  return queue;
}