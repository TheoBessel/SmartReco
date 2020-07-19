# SmartReco
SmartReco is a CNN (Convolutionnal Neural Network) classificator library written in C++ lang. Is goal is to identify element in pictures.

## Code example :

```cpp
#include <SR/Image>
#include <SR/Matrix>
#include <SR/Layer>
#include <SR/Operations>
#include <SR/Data>

int main() {
  SR::Network::Network net(7);                              // 7 Layers
  
  SR::Data::DataSet<SQL> dataset;                           // Entry dataset, type : sql
  
  SR::Network::Layer<Input> in();                           // Input layer
  
  SR::Network::Layer<Conv> conv(Relu);                      // Convolutional layer with ReLU correction
  SR::Network::Layer<Pooling> pool();                       // Pooling layer
  SR::Network::Layer<FullyConnected> fc(SoftMax);           // Fully Connected layer with SoftMax activation
  
  SR::Network::Layer<Output> out(3);                        // Output layer
  out.addType("Plane");                                     // First possibility of output
  out.addType("Bird");                                      // Second possibility of output
  out.addType("Other");                                     // Third possibility of output
  
  SR::Data::ProbablityArray probability;                  // Output probability array
  
  dataset.importFrom<Url>("https://cifar.fr/cifar.sql");    // Input origin
  
  net.addLayers(in, conv, pool, conv, pool, fc, out);       // Network construction
  net.train(dataset.train);                                 // Network training from 'dataset train set'
  net.compute(dataset.test);                                // Network computing from 'dataset test set'
  net.printResult(probability);                             // Network outputing to 'probability array'
  
  return 0;
}
```
