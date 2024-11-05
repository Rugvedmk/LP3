//SPDX-License-Identifier: MIT
pragma solidity ^0.8;

contract Account{
    uint256 public balance;
    address public owner;
    constructor(){
        balance = 0;
        owner = msg.sender;
    }

    function deposite() public payable{
        require(msg.value > 0,"The amount should be greater than 0!");
        balance += msg.value;
    }

    function getBalance() public view returns(uint256 curBalance){
        return (balance);
    }

    function transfer(uint256 money, address adr) public payable{
        require(balance >= money,"Insufficient Balance!");
        require(owner == msg.sender,"The money can only be transfered by the owner!");
        payable(adr).transfer(money);
        balance -= money;
    }

    function withdraw(uint256 money) public payable{
        require(balance >= money,"Insufficient Balance!");
        require(owner == msg.sender,"The money can only be transfered by the owner!");
        payable(msg.sender).transfer(money);
        balance -= money;
    }
}