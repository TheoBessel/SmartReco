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
  SR::Network::Network net(7); // 7 Layers
  
  SR::Data::DataSet<SQL> dataset;
  
  SR::Network::Layer<Input> in();
  
  SR::Network::Layer<Conv> conv(Relu);
  SR::Network::Layer<Pooling> pool();
  SR::Network::Layer<FullyConnected> fc(SoftMax);
  
  SR::Network::Layer<Output> out(3);
  out.addType("Plane");
  out.addType("Bird");
  out.addType("Other");
  
  SR::Data::ProbablityArray<> probability;
  
  dataset.importFrom<Url>("https://cifar.fr/cifar.sql");
  
  net.addLayers(in, conv, pool, conv, pool, fc, out);
  net.train(dataset);
  net.compute(probability);
  net.printResult();
  
  return 0;
}
```
