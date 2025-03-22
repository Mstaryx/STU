from torch import nn, tensor
class Mymodule(nn.Module):
    def __init__(self):
        super(Mymodule,self).__init__()
    def forward(self,x):
        output=x+1
        return output
My_module=Mymodule()
x=tensor(1.0)
output=My_module.forward(x)
print(output)