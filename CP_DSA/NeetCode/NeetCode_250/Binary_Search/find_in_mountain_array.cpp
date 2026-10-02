class Solution {
public:
    int findPeak(MountainArray &arr) {
        int l = 0, r = arr.length() - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (arr.get(mid) < arr.get(mid + 1))
                l = mid + 1;
            else
                r = mid;
        }

        return l;
    }

    int binarySearch(MountainArray &arr, int l, int r,
                     int target, bool ascending) {
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int val = arr.get(mid);

            if (val == target)
                return mid;

            if (ascending) {
                if (val < target)
                    l = mid + 1;
                else
                    r = mid - 1;
            } else {
                if (val < target)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
        }

        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak = findPeak(mountainArr);

        int idx = binarySearch(
            mountainArr, 0, peak, target, true);

        if (idx != -1)
            return idx;

        return binarySearch(
            mountainArr,
            peak + 1,
            mountainArr.length() - 1,
            target,
            false
        );
    }
};