const axios = require('axios');
let baseUrl = "https://jsonmock.hackerrank.com/api/universities";

const solve = async(country) => {
    let maxRank  = 10000000000;
    let result = "";
    let total_pages = 0;

    const pages = await axios.get(
        baseUrl
    );
    total_pages = pages.data.total_pages;
    
    let page = 1;

    while(page <= total_pages){
        const response = await axios.get(
            `${baseUrl}/search?page=${page}`
        );
        const data = response.data.data;

        for(let i=0; i<data.length; i++){
            let univ = data[i];
            if(country === univ.location.country){
                if(parseInt(univ.rank_display) < maxRank){
                    maxRank = univ.rank_display;
                    result = univ.university;
                }
            }           
        }
        page++;
    }
    console.log("Country: ",result);
}


solve("United Kingdom");
