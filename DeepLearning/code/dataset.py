from torch.utils.tensorboard import SummaryWriter
import torchvision
train_set=torchvision.datasets.CIFAR10(root="../Dataset_2",train=True,transform=torchvision.transforms.ToTensor(),download=True)
test_set=torchvision.datasets.CIFAR10(root="../Dataset_2",train=False,download=True)
# print(train_set[0])
writer=SummaryWriter("../logs")
for i in range(0,10):
    print(train_set[i])
    img,target=train_set[i]
    # writer.add_image("datasets1",img,i)
writer.close()