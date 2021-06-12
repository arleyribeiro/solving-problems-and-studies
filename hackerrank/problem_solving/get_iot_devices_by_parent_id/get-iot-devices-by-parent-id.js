const request = require('request');
const fs = require('fs');


async function getPage(statusQuery, page) {
    const response = await myFetch(`https://jsonmock.hackerrank.com/api/iot_devices/search?status=${statusQuery}&page=${page}`);
    return JSON.parse(response);
}

async function myFetch(url) {
    return new Promise((resolve, reject) => {
      request(url, function (error, response, body) {
        if(error) reject(error)
  
        else resolve(body)
      });
    });
  }

function getRootSpeedByParentId(data, parentId) {
    let rootSpeed = 0;
    let numberOfDevices = 0;
    (data || []).forEach((iot) => {
        if (iot && iot.parent && iot.parent.id === parentId) {
            if (iot.operatingParams) {
                rootSpeed += iot.operatingParams.rotorSpeed;
                numberOfDevices++;
            }
        }
    })
    return { rootSpeed, numberOfDevices };
}

async function avgRotorSpeed(statusQuery, parentId) {
    let totalPages = 1;
    let rootSpeedTotal = 0, numberOfDevicesTotal = 0;
    for(let i = 1; i <= totalPages; i++) {
        const response = await getPage(statusQuery, i);
        totalPages = response.total_pages;
        let {rootSpeed, numberOfDevices } = getRootSpeedByParentId(response.data, parentId);    
        rootSpeedTotal += rootSpeed;
        numberOfDevicesTotal += numberOfDevices;
    } 
    return Math.floor(rootSpeedTotal/(numberOfDevicesTotal || 1));
}

async function main() {
    const result = await avgRotorSpeed('RUNNING', 7);
    console.log(result)
}

main()
