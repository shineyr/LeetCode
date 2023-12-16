import kotlin.random.Random
class RandomizedSet() {
    val nums = ArrayList<Int>()
    val indexMap = mutableMapOf<Int, Int>()

    fun insert(value: Int): Boolean {
        if (!indexMap.contains(value)) {
            nums.add(value)
            indexMap.put(value, nums.size - 1)
            return true
        }
        return false
    }

    fun remove(`val`: Int): Boolean {
        if (!indexMap.contains(`val`)) {
            return false
        }

        val valIdx = indexMap.get(`val`)!!
        nums[valIdx] = nums[nums.size - 1]
        indexMap.put(nums[nums.size-1], valIdx)

        indexMap.remove(`val`)
        nums.removeAt(nums.size-1)

        return true
    }

    fun getRandom(): Int {
        val randomIdx = Random.nextInt(0, nums.size)
        return nums[randomIdx]
    }

}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * var obj = RandomizedSet()
 * var param_1 = obj.insert(`val`)
 * var param_2 = obj.remove(`val`)
 * var param_3 = obj.getRandom()
 */
