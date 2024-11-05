//SPDX-License-Identifier: MIT
pragma solidity ^0.8;

contract School{
    struct Student{
        uint256 id;
        string name;
    }

    Student []students;

    event Log(string str);
    function addStudent(uint256 id,string memory name) public {
        bool sameId = false;
        for(uint256 i = 0;i<students.length;i++){
            if(students[i].id == id){
                sameId = true;
                break;
            }
        }
        if(sameId){
            emit Log("Id repeated");
            return;
        }

        Student memory temp = Student(id,name);
        students.push(temp);
    }

    function getStudent(uint256 id) public view returns(uint256 Id,string memory name){
        for(uint256 i = 0;i<students.length;i++){
            if(id == students[i].id){
                return(students[i].id,students[i].name);
            }
        }
    }

    function deleteStudent(uint256 id) public {
        uint256 index = 0;
        bool deleted = false;
        for(uint256 i = 0;i<students.length;i++){
            if(id == students[i].id){
                delete students[i];
                deleted = true;
                index = i;
                break;
            }
        }

        if(deleted){
            for(uint256 i = index;i<students.length-1;i++){
                students[i] = students[i+1];
            }
        } else {
            emit Log("No student found");
            return;
        }

        students.pop();
    }

    event Logi(string str,uint256 amt,bytes data);
    fallback() external payable {
        emit Logi("Fallback",msg.value,msg.data);
    }

    receive() external payable { 
        emit Logi("Receive",msg.value,"");
    }
}