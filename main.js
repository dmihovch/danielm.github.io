let num_pets = 0;
const pets_counter = document.getElementById("num-pets")
document.getElementById("pet-btn").addEventListener("click",addPet)



function addPet()
{
	num_pets++;
	pets_counter.textContent = num_pets;

}
